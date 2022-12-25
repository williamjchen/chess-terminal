#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

const int FRAME_DELAY = 100; // Delay between frames in milliseconds

// A class to represent a frame of the animation
class Frame {
public:
  std::string data;
  int delay; // Delay for this frame in milliseconds

  Frame(const std::string& data, int delay) : data(data), delay(delay) {}
};

// A class to represent an ASCII animation
class Animation {
public:
  std::vector<Frame> frames; // The frames of the animation

  // Add a frame to the animation
  void addFrame(const Frame& frame) {
    frames.push_back(frame);
  }

  // Play the animation
  void play() {
    for (const Frame& frame : frames) {
      std::cout << frame.data << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(frame.delay));
      std::cout << "\033[2J\033[1;1H"; // Clear the screen
    }
  }
};

int main() {
  // Create an animation
  Animation animation;

  // Add some frames to the animation
  animation.addFrame(Frame("                                            .         ", FRAME_DELAY));
  animation.addFrame(Frame("                                         .:;:,.       ", FRAME_DELAY));
  animation.addFrame(Frame("                                        .:;:;;:       ", FRAME_DELAY));
  animation.addFrame(Frame("                                        .:;:;;;:      ", FRAME_DELAY));
  animation.addFrame(Frame("                                        .:;:;;;:      ", FRAME_DELAY));
  animation.addFrame(Frame("                                        .:;:;;;:      ", FRAME_DELAY));
  animation.addFrame(Frame("                                        .:;:;;;:      ", FRAME_DELAY));
  animation.addFrame(Frame("                                        .:;:;;;:      ", FRAME_DELAY));
  animation.addFrame(Frame("                                        .:;:;;:       ", FRAME_DELAY));
  animation.addFrame(Frame("                                         .:;:;.       ", FRAME_DELAY));
  animation.addFrame(Frame("                                            .         ", FRAME_DELAY));

  // Play the animation
  animation.play();
}
