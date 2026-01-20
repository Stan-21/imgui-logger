#pragma once

#include "imgui/imgui.h"
#include <vector>
#include <fstream>
#include <string>

enum class LEVEL {
    INFO,
    WARNING,
    ERROR
};

class Logger {
    private:

        struct Log {
            LEVEL level;
            std::string message;
            ImVec4 color;
            bool game;
            Log(std::string t, LEVEL l, bool g, ImVec4 c);
        };
        
        Logger();
        ~Logger();

        static Logger* instance;
        std::ofstream File;
        std::vector<Log> LogHistory;
        LEVEL LogLevel = LEVEL::INFO;
    public:
        static Logger& GetInstance() {
            if (instance == nullptr) {
                instance = new Logger();
            }
            return *instance;
        }
        void LogInfo(std::string s);
        void LogWarning(std::string s);
        void LogError(std::string s);
        void LogGameEvent(std::string s);
        void Render();

};