#include <iostream>
#include <SimpleHDLViewer.h>

int main (int argc, char ** argv)
{
  std::string hdlCalibration, pcapFile;

  parse_argument (argc, argv, "-calibrationFile", hdlCalibration);
  parse_argument (argc, argv, "-pcapFile", pcapFile);

  pcl::HDLGrabber grabber (hdlCalibration, pcapFile);
  pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZI> color_handler ("z");

//  pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZI> color_handler ("intensity");
  //printf("color_handler.name: %s\n", color_handler.getName().c_str());
  printf("color_handler.field: %s\n", color_handler.getFieldName().c_str());

  SimpleHDLViewer v(grabber, color_handler);
  v.run ();
  return (0);
}
