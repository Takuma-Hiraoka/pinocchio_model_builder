#include "pinocchio_model_builder/pinocchio_model_builder.h"

namespace pinocchio_model_builder {
  void buildModel(pinocchio::ModelTpl<double>& model, const std::string& urdfPath, const std::vector<std::string>& fixedJointNames, const pinocchio::JointModelComposite& baseJointComposite, urdf::ModelInterfaceSharedPtr urdfModel) {
    urdfModel = urdf::parseURDFFile(urdfPath);
    if (!urdfModel) {
      std::cerr << __func__ << "error!! cannnot load " << urdfPath << std::endl;
    }

    for (std::pair<const std::string, std::shared_ptr<urdf::Joint>> jointPair : urdfModel->joints_ ) {
      if (std::find(fixedJointNames.begin(), fixedJointNames.end(), jointPair.first) != fixedJointNames.end()) jointPair.second->type = urdf::Joint::FIXED;
    }

    pinocchio::urdf::buildModel(urdfModel, baseJointComposite, model);

  }
}
