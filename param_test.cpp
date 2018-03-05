#include <ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ns_test");
  ros::NodeHandle nh("~");
  std::cout << ros::this_node::getNamespace() << std::endl;
  std::cout << nh.getNamespace() << std::endl;

  std::vector<std::string> keys;
  nh.getParamNames(keys);
  // for (size_t i = 0; i < keys.size(); ++i)
  //   ROS_INFO_STREAM(keys[i]);

  //

  XmlRpc::XmlRpcValue list1;
  nh.getParam("/home", list1);

  for(XmlRpc::XmlRpcValue::ValueStruct::const_iterator it = list1.begin();
      it != list1.end(); ++it)
  {
    ROS_INFO_STREAM(it->first);
    XmlRpc::XmlRpcValue list2 = it->second;
    for(XmlRpc::XmlRpcValue::ValueStruct::const_iterator it2 = list2.begin();
        it2 != list2.end(); ++it2)
    {
      XmlRpc::XmlRpcValue xml_rpc_value = it2->second;
      if (xml_rpc_value.getType() != XmlRpc::XmlRpcValue::TypeDouble)
        continue;

      const double value = static_cast<double>(xml_rpc_value);
      ROS_INFO_STREAM(it2->first << " " << value);
    }
  }

  // ros::spin();
  return 0;
}
