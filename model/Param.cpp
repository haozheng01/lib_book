//
// Created by 修齐 on 2025/9/12.
//

#include "Param.h"
#include <json/json.h>
#include <iostream>

std::string Param::GetName(void)
{
    return name;
}

std::string Param::GetBody(void)
{
    return  body;
}
std::string Param::GetParams(void)
{
    return {params.begin(), params.end()};
}

std::string Param::ToJsonStr(void)
{
    Json::Value root;
    root["name"] = name;
    root["body"] = body;

    Json::Value paramsArray;
    for (auto param : params) {
        paramsArray.append(param);
    }
    root["params"] = paramsArray;

    Json::StreamWriterBuilder builder;
    return Json::writeString(builder, root);
}

int Param::ParseJson(const std::string &json)
{
    if (json.empty()) {

        return -1;
    }
    Json::Value root;
    std::istringstream jsonStream(json);
    Json::CharReaderBuilder builder;
    std::string parseErrors;
    bool ret = Json::parseFromStream(builder, jsonStream, &root, &parseErrors);
    if (!ret) {
        std::cerr << "json parse failed! " << parseErrors << std::endl;
        return -1;
    }
    if (root.isMember("name")) {
        this->name = root["name"].asString();
    }
    if (root.isMember("body")) {
        this->body = root["body"].asString();
    }
    if (root.isMember("params") && root["params"].isArray()) {
        this->params.clear();
        this->params.shrink_to_fit();
        const Json::Value& pms = root["params"];
        for (Json::ArrayIndex  i = 0; i < pms.size(); i++) {
            this->params.push_back(static_cast<uint8_t>(pms[i].asUInt()));
        }
    }

    return 0;
}