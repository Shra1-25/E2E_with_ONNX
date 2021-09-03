#ifndef PHYSICSTOOLS_ONNXRUNTIME_INTERFACE_ONNXRUNTIME_H_
#define PHYSICSTOOLS_ONNXRUNTIME_INTERFACE_ONNXRUNTIME_H_

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "onnxruntime/core/session/onnxruntime_cxx_api.h"

namespace cms::Ort {
	
	typedef std::vector<std::vector<float>> FloatArrays;
	class ONNXRuntime {
	public:
		ONNXRuntime(const std::string& model_path, const ::Ort::SessionOptions* session_options = nullptr);
		ONNXRuntime(const ONNXRuntime&) = delete;
		ONNXRuntime& operator=(const ONNXRuntime&) = delete;
		~ONNXRuntime();
		
		FloatArrays run(const std::vector<std::string>& input_names,
				FloatArrays& input_values,
				//std::vector<std::vector<std::vector<std::vector<float>>>>,
				//std::vector<std::vector<std::vector<std::vector<float>>>>,
				const std::vector<std::vector<int64_t>>& input_shapes = {},
				const std::vector<std::string>& output_names = {},
				int64_t batch_size = 1) const;
		
		// Get a list of names of all the output nodes
		const std::vector<std::string>& getOutputNames() const;
	
		// Get the shape of a output node
		// The 0th dim depends on the batch size, therefore is set to -1
		const std::vector<int64_t>& getOutputShape(const std::string& output_name) const;
	private:
		static const ::Ort::Env env_;
		std::unique_ptr<::Ort::Session> session_;
		
		std::vector<std::string> input_node_strings_;
		std::vector<const char*> input_node_names_;
		std::map<std::string, std::vector<int64_t>> input_node_dims_;
		
		std::vector<std::string> output_node_strings_;
		std::vector<const char*> output_node_names_;
		std::map<std::string, std::vector<int64_t>> output_node_dims_;
	};
} // namespace cms::Ort

#endif /* PHYSICSTOOLS_ONNXRUNTIME_INTERFACE_ONNXRUNTIME_H_ */
