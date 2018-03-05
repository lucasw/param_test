#include <ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "string_param_test");
  ros::NodeHandle nh("~");
  // std::cout << ros::this_node::getNamespace() << "\n";
  // std::cout << nh.getNamespace() << "\n";

  std::string test = "";
  nh.getParam("str_param", test);
  std::cout << test << "\n";

  nh.setParam("str_param2", "12345");
  nh.getParam("str_param2", test);
  std::cout << test << "\n";

  return 0;
}
