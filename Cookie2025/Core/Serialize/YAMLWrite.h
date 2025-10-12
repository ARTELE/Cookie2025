#pragma once
#include <string>
#include "SerializeTraits.h"
#include "SerializeBase.h"
#include <ThirdPartLib/yaml/include/yaml-cpp/yaml.h>
#include <stack>

namespace cookie
{
	namespace core
	{
		class YAMLWrite : public SerializeBase<YAMLWrite>
		{
			std::shared_ptr<YAML::Node> root = nullptr;
			std::stack<std::shared_ptr<YAML::Node>> nodeStack;
		public:

			YAMLWrite()
			{
				root = std::make_shared<YAML::Node>();
				nodeStack.push(root);
			}

			template<typename T>
			void Serialize(T& data, const std::string& name)
			{
				std::shared_ptr<YAML::Node> node = std::make_shared<YAML::Node>();
				nodeStack.push(node);
				data.Serialize(*this);
				nodeStack.pop();
				(*(nodeStack.top()))[name] = *node;
			}

			template<>
			void Serialize(uint32_t& data, const std::string& name)
			{
				auto& currentNode = nodeStack.top();
				(*currentNode)[name] = data;
			}

			template<>
			void Serialize(int32_t& data, const std::string& name)
			{
				auto& currentNode = nodeStack.top();
				(*currentNode)[name] = data;
			}


			template<>
			void Serialize(uint16_t& data, const std::string& name)
			{
				auto& currentNode = nodeStack.top();
				(*currentNode)[name] = data;
			}
		};
	}
}
