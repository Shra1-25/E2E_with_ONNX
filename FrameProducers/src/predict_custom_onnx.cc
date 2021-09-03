#include "RecoE2E/FrameProducers/interface/predict_custom_onnx.h"

using namespace cms::Ort;

e2e::Frame2D e2e::predict_custom_onnx(FloatArrays& input_values, int batch_size){
	std::string model_path = edm::FileInPath("RecoE2E/onnxModels/trial2.onnx").fullPath();
	ONNXRuntime rt(model_path);
        //FloatArrays input_values(4,std::vector<float>(2,1.));
        e2e::Frame2D outputs;
	//tuple <e2e::Frame2D,e2e::Frame2D,e2e::Frame2D> input_values;
	//input_values = make_tuple(vadd1, vadd2, vmul1); 
	//std::vector<std::vector<std::vector<std::vector<float>>>> input1 = {{{{1,2},{3,4}},{{5,6},{7,8}}},{{{9,10},{11,12}},{{13,14},{15,16}}}};
	//std::vector<std::vector<std::vector<std::vector<float>>>> input2 = {{{{11,12},{13,14}},{{15,16},{17,18}}},{{{19,110},{111,112}},{{113,114},{115,116}}}};
	std::cout<<"start3"<<endl;
	outputs = rt.run({"coords0", "coords1","edge_from", "edge_to"}, input_values, {}, {"outputs"}, batch_size);
        std::cout<<"Outputs: ";
        for (unsigned int i=0;i<outputs.size();i++){
                for (unsigned int j=0;j<outputs[0].size();j++){
                        std::cout<<outputs[i][j]<<" ";
                }
        }
        std::cout<<std::endl;
        return outputs;
}

