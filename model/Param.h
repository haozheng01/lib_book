//
// Created by 修齐 on 2025/9/12.
//

#ifndef LIB_BOOK_PARAM_H
#define LIB_BOOK_PARAM_H

#include <string>
#include <utility>
#include <vector>

class Param {
public:
    Param() : name(), body(), params() {};
    Param(const std::string& name, const std::string&body, const std::vector<uint8_t>& params) : name(name), body(body), params(params) {};

    std::string ToJsonStr(void);
    int ParseJson(const std::string &json);

    std::string GetName(void);
    std::string GetBody(void);
    std::string GetParams(void);
private:
    std::string name;
    std::string body;
    std::vector<uint8_t> params;
};


#endif //LIB_BOOK_PARAM_H
