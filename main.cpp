#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

struct AIRecommendation {
    std::string modelName;
    std::string primaryUseCase;
    std::string whySelected;
    std::vector<std::string> queryHistory;
    std::map<std::string, int> modelStats;
};

// Convert string to lowercase for case-insensitive matching
std::string toLower(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return text;
}

AIRecommendation recommendAI(const std::string& prompt) {
    std::string lowerPrompt = toLower(prompt);

    // Rule 1: Local / Privacy / Offline
    if (lowerPrompt.find("offline") != std::string::npos || 
        lowerPrompt.find("privacy") != std::string::npos || 
        lowerPrompt.find("local") != std::string::npos ||
        lowerPrompt.find("sensitive") != std::string::npos) {
        return {
            "Ollama / Llama 3 (Local)",
            "Data privacy & offline generation",
            "You mentioned privacy or running offline. Local models keep all data safely on your machine without third-party API tracking."
        };
    }

    // Rule 2: Deep Coding / Debugging / Software Architecture
    if (lowerPrompt.find("code") != std::string::npos || 
        lowerPrompt.find("programming") != std::string::npos || 
        lowerPrompt.find("debug") != std::string::npos ||
        lowerPrompt.find("cpp") != std::string::npos ||
        lowerPrompt.find("python") != std::string::npos) {
        return {
            "Claude 3.5 Sonnet / Claude 3.7 Sonnet",
            "Coding, refactoring, and logical reasoning",
            "Your query is related to programming. Claude models excel at accurate code generation, debugging, and complex logic."
        };
    }

    // Rule 3: Math, Reasoning, & Complex Logic
    if (lowerPrompt.find("math") != std::string::npos || 
        lowerPrompt.find("logic") != std::string::npos || 
        lowerPrompt.find("solve") != std::string::npos ||
        lowerPrompt.find("algorithm") != std::string::npos) {
        return {
            "OpenAI o1 / o3-mini",
            "Deep reasoning and mathematical problem solving",
            "Your prompt involves logic or math. OpenAI's reasoning models spend time 'thinking' step-by-step before answering complex problems."
        };
    }

    // Rule 4: Huge Files / Long Documents / PDF Analysis
    if (lowerPrompt.find("pdf") != std::string::npos || 
        lowerPrompt.find("book") != std::string::npos || 
        lowerPrompt.find("long document") != std::string::npos ||
        lowerPrompt.find("video") != std::string::npos) {
        return {
            "Google Gemini 1.5 Pro / Gemini 2.0 Flash",
            "Large context windows (up to 2M tokens) and multimodal inputs",
            "Gemini handles massive context lengths seamlessly, making it best for analyzing whole codebases, huge PDFs, or long videos."
        };
    }

    // Default: General Knowledge, Web Search, Fast Chat
    return {
        "ChatGPT (GPT-4o) or Perplexity AI",
        "General questions, real-time web search, everyday tasks",
        "Your query appears to be a general question. GPT-4o provides fast, well-rounded answers, while Perplexity offers live web sources."
    };
}

int main() {
    std::cout << "=================================================\n";
    std::cout << "         AI MODEL ADVISOR (C++ Engine)          \n";
    std::cout << "=================================================\n";
    std::cout << "Describe what task you are trying to accomplish.\n";
    std::cout << "(Type 'exit' to quit)\n\n";

    std::string userInput;
    while (true) {
        std::cout << "Your Query > ";
        std::getline(std::cin, userInput);

        if (userInput == "exit" || userInput == "quit") {
            std::cout << "Goodbye!\n";
            break;
        }

        if (userInput.empty()) continue;

        if (userInput == "history") {
    std::cout << "\n===== QUERY HISTORY =====\n";

        } if (queryHistory.empty()) {
        std::cout << "No queries yet.\n";
    } else {
        for (size_t i = 0; i < queryHistory.size(); i++) {
            std::cout << i + 1 << ". " << queryHistory[i] << "\n";
        }
    }

    std::cout << "=========================\n\n";
    continue;
}
    if (userInput == "stats") {
std::cout << "\n===== AI MODEL USAGE =====\n";
 
for (const auto& model : modelStats) {
std::cout << model.first << " : "
<< model.second << " recommendations\n";
}
 
std::cout << "==========================\n\n";
continue;
}

        AIRecommendation recommendation = recommendAI(userInput);

        std::cout << "\n-------------------------------------------------\n";
        std::cout << "  RECOMMENDED BOT : " << recommendation.modelName << "\n";
        std::cout << "  BEST USE CASE   : " << recommendation.primaryUseCase << "\n";
        std::cout << "  REASON          : " << recommendation.whySelected << "\n";
        std::cout << "-------------------------------------------------\n\n";
    }

    return 0;
}
