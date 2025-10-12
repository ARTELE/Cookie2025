#pragma once
#include <string>
#include "SerializeTraits.h"
#include <ThirdPartLib/yaml/include/yaml-cpp/yaml.h>
#include <stack>

namespace cookie
{
	namespace core
	{
		template<typename T>
		class SerializeBase
		{
			inline T& self() { return *static_cast<T*>(this); }
		public:
			template<typename T>
			void SerializeRoot(T& data)
			{
				self().Serialize(data, SerializeTraits<T>::GetTypeString());
			}
		};

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
			template<typename BuiltInType>
			void Serialize(BuiltInType& data, const std::string& name)
			{
				auto& currentNode = nodeStack.top();
				(*currentNode)[name] = data;
			}

			template<>
			void Serialize(int& data, const std::string& name)
			{
				auto& currentNode = nodeStack.top();
				(*currentNode)[name] = data;
			}

			template<typename T>
			void Serialize(T& data, const std::string& name)
			{
				std::shared_ptr<YAML::Node> node = std::make_shared<YAML::Node>();
				nodeStack.push(node);
				data.Serialize(this);
				nodeStack.pop();
				(*nodeStack.top())[name] = node;
			}
		};
	}
}
