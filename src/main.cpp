#include <vector>
#include <string>
#include <iostream>

#include <glog/logging.h>
#include <opencv2/opencv.hpp>
#include <opencv2/saliency.hpp>

class Bing : public cv::saliency::ObjectnessBING {
   public:
    Bing(const std::string& model, const std::string& result) {
        setTrainingPath(model);
        setBBResDir(result);
    }
    void Detect(const cv::Mat& image, std::vector<cv::Vec4i>& bbs,
                std::vector<float>& objness_vals) {
        computeSaliencyImpl(image, bbs);
        objness_vals = getobjectnessValues();
    }
};

int main(int argc, char** argv) {
    FLAGS_logtostderr = 1;
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();

    if (argc < 3) {
        std::cout << "Usage: ./opencv_bing_test MODEL IMAGE" << std::endl;
        return 1;
    }

    Bing bing(argv[1], "./result");
    cv::Mat image = cv::imread(argv[2], 1);

    std::vector<cv::Vec4i> bbs;
    std::vector<float> objness_vals;
    bing.Detect(image, bbs, objness_vals);

    cv::Mat bbs_image = image.clone();

    std::cout << "num bbs : " << bbs.size() << std::endl;
    for (int i = 0; i < bbs.size(); ++i) {
        if (i < bbs.size() - 1000) {
            continue;
        }
        // std::cout << bbs[i] << " " << objness_vals[i] << std::endl;
        cv::Point pt1(bbs[i][0], bbs[i][1]);
        cv::Point pt2(bbs[i][2], bbs[i][3]);

        cv::rectangle(bbs_image, pt1, pt2, cv::Scalar(255, 0, 0));
    }

    cv::namedWindow("Top 1000 BBs");
    cv::imshow("Top 1000 BBs", bbs_image);
    cv::waitKey(0);

    return 0;
}
