#include "Logger.h"
#include "imgui/imgui.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


Logger::Log::Log(std::string t, LEVEL l, bool g, ImVec4 c) {
    std::chrono::time_point tp = std::chrono::system_clock::now();
    std::string time = std::format("{:%H:%M:%S}", tp);
    
    level = l;
    game = g;
    message = "[" + time + "]";
    if (l == LEVEL::INFO) {
        message += " [INFO] ";
    }
    if (l == LEVEL::WARNING) {
        message += " [WARN] ";
    }
    if (l == LEVEL::ERROR) {
        message += " [ERROR] ";
    }
    message += game ? "[GAME] " + t : t;
    color = c;
}

Logger::Logger() {
    File.open("log.txt");
}

Logger::~Logger() {
    File.close();
}

void Logger::LogInfo(std::string s) {
    Log* l = new Log(s, LEVEL::INFO, false, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    LogHistory.push_back(*l);
    File << l->message << std::endl;
}

void Logger::LogWarning(std::string s) {
    Log* l = new Log(s, LEVEL::WARNING, false, ImVec4(1.0f, 1.0f, 0.0f, 1.0f));
    LogHistory.push_back(*l);
    File << l->message << std::endl;
}

void Logger::LogError(std::string s) {
    Log* l = new Log(s, LEVEL::ERROR, false, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
    LogHistory.push_back(*l);
    File << l->message << std::endl;
}

void Logger::LogGameEvent(std::string s) {
    Log* l = new Log(s, LEVEL::INFO, true, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    LogHistory.push_back(*l);
    File << l->message << std::endl;
}

void Logger::Render() {
    ImGui::Begin("Game Log");

    if (ImGui::Button("Options")) {
        if (LogLevel == LEVEL::INFO) {
            LogLevel = LEVEL::WARNING;
        } else if (LogLevel == LEVEL::WARNING) {
            LogLevel = LEVEL::ERROR;
        } else if (LogLevel == LEVEL::ERROR) {
            LogLevel = LEVEL::INFO;
        }
    }
    ImGui::SameLine();
    if (ImGui::Button("Clear")) {
        File << "*** Console log cleared ***" << std::endl;
        LogHistory.clear();
    }
    ImGui::SameLine();
    if (ImGui::Button("Test Info")) {
        LogInfo("This is a test info message");
    }
    ImGui::SameLine();
    if (ImGui::Button("Test Warning")) {
        LogWarning("This is a test warning message");
    }
    ImGui::SameLine();
    if (ImGui::Button("Test Error")) {
        LogError("This is a test error message");
    }
    ImGui::Separator();

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_HorizontalScrollbar;

    ImGui::BeginChild("ChildL", ImVec2(ImGui::GetContentRegionAvail()), ImGuiChildFlags_None, window_flags);
    for (Log &n: LogHistory) {
        if (n.level >= LogLevel) {
            ImGui::TextColored(n.color, "%s", (n.message).c_str());
        }
    }
    ImGui::EndChild();
    ImGui::End();
}

Logger* Logger::instance = nullptr;