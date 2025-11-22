#include "FileExplorerWindow.h"
#include <imgui_internal.h>
#include <filesystem>

using namespace cookie::editor;

void FileExplorerWindow::BuildFileTreeInternal(const std::string& directoryPath, FileTreeNode& node)
{
    std::filesystem::path rootPath(directoryPath);
    for (const auto& entry : std::filesystem::directory_iterator(rootPath))
    {
        FileTreeNode childNode;
        childNode.name = entry.path().filename().string();
        childNode.isDirectory = entry.is_directory();
        if (childNode.isDirectory)
        {
            BuildFileTreeInternal(entry.path().string(), childNode);
        }
        node.children.push_back(childNode);
	}
}

void FileExplorerWindow::DrawFileTreeItem(const FileTreeNode& node)
{
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    ImGuiTreeNodeFlags tree_node_flags_base =  ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_DrawLinesFull;
    ImGuiTreeNodeFlags node_flags = tree_node_flags_base;
    if (node.isDirectory)
    {
        bool open = ImGui::TreeNodeEx(node.name.c_str(), node_flags);
        if (open)
        {
            for (int i = 0; i < node.children.size(); i++)
                DrawFileTreeItem(node.children[i]);
            ImGui::TreePop();
        }
    }
    else
    {
        ImGui::TreeNodeEx(node.name.c_str(), node_flags | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Bullet | ImGuiTreeNodeFlags_NoTreePushOnOpen);
    }
}

void FileExplorerWindow::DrawFileTree(const FileTreeNode& node)
{
    ImGuiTableFlags table_flags = ImGuiTableFlags_NoBordersInBody;
    if (ImGui::BeginTable("3ways", 1, table_flags))
    {  
        DrawFileTreeItem(node);
        ImGui::EndTable();
    }
       
}

void FileExplorerWindow::OnGui()
{
    ImGui::BeginChild("left pane", ImVec2(150, 0), ImGuiChildFlags_Borders | ImGuiChildFlags_ResizeX);
 
    DrawFileTree(node);

    ImGui::EndChild();
    ImGui::SameLine();
}