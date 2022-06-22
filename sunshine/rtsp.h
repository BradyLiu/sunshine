//
// Created by loki on 2/2/20.
//

#ifndef SUNSHINE_RTSP_H
#define SUNSHINE_RTSP_H

#include <atomic>

#include "crypto.h"
#include "thread_safe.h"

namespace stream {
constexpr auto RTSP_SETUP_PORT = 21;

class rtsp_server_t;

struct launch_session_t {
  crypto::aes_t gcm_key;
  crypto::aes_t iv;

  bool host_audio;
};

class rtsp_group{
public:

  static rtsp_group& getInstance(){
    static rtsp_group group;
    return group;
  }

  void launch_session_raise(launch_session_t launch_session);
  int session_count();

  void start_group();
  bool rtsp_thread(rtsp_server_t* server);

private:
  rtsp_group();
  ~rtsp_group();

  std::map<int, rtsp_server_t*> servers_;
};

} // namespace stream

#endif //SUNSHINE_RTSP_H
