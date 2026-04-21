#pragma once

#include <pinocchio/fwd.hpp>
#include <pinocchio/multibody/model.hpp>
#include <pinocchio/parsers/urdf.hpp>
#include <urdf_parser/urdf_parser.h>

namespace pinocchio_model_builder {
  pinocchio::JointModelComposite getBaseJointcomposite();

  void buildModel(pinocchio::ModelTpl<double>& model, const std::string& urdfPath, const std::vector<std::string>& fixedJointNames, const pinocchio::JointModelComposite& baseJointComposite=getBaseJointcomposite(), urdf::ModelInterfaceSharedPtr urdfModel=nullptr);
}
