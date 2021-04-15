#pragma once

#include <memory>

#include "engine/alice/alice.hpp"
#include "messages/messages.hpp"

namespace benchbot {

class SegmentPublisher : public isaac::alice::Codelet {
 public:
  SegmentPublisher() {}
  virtual ~SegmentPublisher() {}

  void start() override;
  void stop() override;
  void tick() override;

  ISAAC_PARAM(std::string, segment_channel_name, "/camera/segment/segment_msg");
  ISAAC_PARAM(std::string, segment_frame_name, "robot_left_camera");

  ISAAC_PARAM(std::string, info_channel_name, "/camera/segment/camera_info");
  ISAAC_PARAM(double, info_fx, 480.0);
  ISAAC_PARAM(double, info_fy, 480.0);
  ISAAC_PARAM(double, info_center_x, 480.0);
  ISAAC_PARAM(double, info_center_y, 270.0);

  ISAAC_PROTO_RX(SegmentationCameraProto, camera_segment);

 private:
  struct RosData;
  std::unique_ptr<RosData> ros_data_;
  std::vector<uint16_t> class_ids_;
  std::vector<std::vector<uint16_t>> class_inst_ids_;
};

}  // namespace benchbot

ISAAC_ALICE_REGISTER_CODELET(benchbot::SegmentPublisher);
