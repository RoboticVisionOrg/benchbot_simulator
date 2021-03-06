#pragma once

#include <memory>
#include <string>

#include "engine/alice/alice.hpp"
#include "messages/messages.hpp"

namespace benchbot {

class RgbPublisher : public isaac::alice::Codelet {
 public:
  RgbPublisher() {}
  virtual ~RgbPublisher() {}

  void start() override;
  void stop() override;
  void tick() override;

  ISAAC_PARAM(std::string, rgb_channel_name, "/camera/color/image_raw");
  ISAAC_PARAM(std::string, rgb_frame_name, "robot_left_camera");

  ISAAC_PARAM(std::string, info_channel_name, "/camera/color/camera_info");
  ISAAC_PARAM(double, info_fx, 480.0);
  ISAAC_PARAM(double, info_fy, 480.0);
  ISAAC_PARAM(double, info_center_x, 480.0);
  ISAAC_PARAM(double, info_center_y, 270.0);

  ISAAC_PROTO_RX(ColorCameraProto, camera_rgb);

 private:
  struct RosData;
  std::unique_ptr<RosData> ros_data_;
};

}  // namespace benchbot

ISAAC_ALICE_REGISTER_CODELET(benchbot::RgbPublisher);
