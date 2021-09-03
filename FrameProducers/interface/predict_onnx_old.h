#ifndef RecoE2E_predict_onnx_h
#define RecoE2E_predict_onnx_h

//#include <cppunit/extensions/HelperMacros.h>
#include "PhysicsTools/ONNXRuntime/interface/ONNXRuntime.h"
#include "FWCore/ParameterSet/interface/FileInPath.h"
#include "RecoE2E/DataFormats/interface/FrameCollections.h"
#include <chrono>
#include <tuple>
#include <iostream>

using namespace std;
using namespace cms::Ort;

namespace e2e {
  e2e::Frame2D predict_onnx(FloatArrays&, int);
}
#endif
