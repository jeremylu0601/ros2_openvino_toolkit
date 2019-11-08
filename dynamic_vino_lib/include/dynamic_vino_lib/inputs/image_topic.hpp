// Copyright (c) 2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @brief A header file with declaration for ImageTopic class
 * @file image_topic.h
 */

#ifndef DYNAMIC_VINO_LIB__INPUTS__IMAGE_TOPIC_HPP_
#define DYNAMIC_VINO_LIB__INPUTS__IMAGE_TOPIC_HPP_

#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <memory>
#include "dynamic_vino_lib/utils/mutex_counter.hpp"
#include "dynamic_vino_lib/inputs/base_input.hpp"

namespace Input
{
/**
 * @class ImageTopic
 * @brief Class for recieving a realsense camera topic as input.
 */
class ImageTopic : public BaseInputDevice, public rclcpp::Node
{
public:
  ImageTopic();
  ImageTopic(std::string &);
  bool initialize() override;
  bool initialize(size_t width, size_t height) override
  {
    return true;
  }
  bool read(cv::Mat * frame) override;

private:
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_;
  cv::Mat image_;
  MutexCounter image_count_;

  void cb(sensor_msgs::msg::Image::UniquePtr image_msg);
};
}  // namespace Input

#endif  // DYNAMIC_VINO_LIB__INPUTS__IMAGE_TOPIC_HPP_
