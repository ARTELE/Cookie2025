#pragma once
#include "UIElement/Widget.h"
#include <vector>

namespace cookie
{ 
	namespace editor
	{
		struct FileTreeNode
		{
			std::string name;
			std::string path;
			bool isDirectory = true;
			std::vector<FileTreeNode> children;
			bool isExpanded = false;
		};

		class FileExplorerWindow : public Widget
		{
			FileTreeNode node;
			void BuildFileTreeInternal(const std::string& directoryPath, FileTreeNode& node);
			void DrawFileTree(const FileTreeNode& node);
			void DrawFileTreeItem(const FileTreeNode& node);
		public:
			FileExplorerWindow() {}

			void BuildFileTree(const std::string& directoryPath)
			{
				BuildFileTreeInternal(directoryPath, node);
			}

			virtual void OnGui() override;
			virtual ~FileExplorerWindow() {}
		};
	}
}