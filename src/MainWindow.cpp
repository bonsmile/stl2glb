#include "MainWindow.h"
#include "imgui/imgui.h"
#include "portable-file-dialogs.h"
#include "lxd/debug.h"

void MainWindow() {
	ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
	ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
	ImGui::Begin("stl2glb", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
	{
		if(ImGui::Button("选择 STL 文件")) {
			auto dialog = pfd::open_file("Select file to open", "", {"All files", "*.stl"}, true);

			for(auto& file : dialog.result()) {
				lxd::print("select file:{}\n", file);
			}
		}
	}
	ImGui::End();
}