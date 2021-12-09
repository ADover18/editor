#include<iostream>
#include<string>
#include<vector>

#pragma once
class TextBuffer
{
private:
    std::vector<std::string> lines;

public:
    int get_length() {
        return this->lines.size();
    }

    std::string get_line(int idx) {
        return this->lines[idx];
    }

    std::vector<std::string> get_lines() {
        return this->lines;
    }

    void set_line(std::string input) {
        input.append("\n");
        this->lines.push_back(input);
    }

    void set_line_idx(std::string input, int idx) {
        input.append("\n");
        this->lines[idx] = input;
    }

    void print() {
        for_each(this->lines.cbegin(), this->lines.cend(),
            [](std::string line) {
                std::cout << line;
            }
        );
    }

    void search(std::string term){
        for (int i = 0 ; i < this->get_length(); ++i ){
            std::string line = this->get_line(i);
            if (line.find(term) != std::string::npos) {
                ++i;
                std::cout << std::to_string(i) << " " << line;
            }
        }
    }

} text_buffer;