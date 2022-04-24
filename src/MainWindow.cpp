#include "MainWindow.h"
#include "imgui/imgui.h"
#include "portable-file-dialogs.h"
#include "lxd/debug.h"
#include "lxd/glb.h"
#include "lxd/fileio.h"
#include "lxd/encoding.h"
#include "lxd/strings/str_replace.h"

void MainWindow() {
	ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
	ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
	ImGui::Begin("stl2glb", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
	{
		if(ImGui::Button("select STL files")) {
			auto dialog = pfd::open_file("Select file to open", "", {"All files", "*.stl"}, true);

			for(auto& file : dialog.result()) {
				std::string buffer = lxd::ReadFile(lxd::utf8_decode(file).c_str());
				lxd::Glb glb;
				if(glb.loadFromStl(buffer)) {
					auto glbPath = absl::StrReplaceAll(file, {{".stl", ".glb"}, {".STL", ".glb"}});
					glb.save(lxd::utf8_decode(glbPath));
				}
			}
		}
	}
	ImGui::End();
}