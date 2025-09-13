#include <iostream>
#include <vector>
#include "model/Param.h"

int main() {
    Param param;
    std::cout << param.ToJsonStr() << std::endl;
    Param param1("name", "body", std::vector<uint8_t>(0));
    std::cout << param1.ToJsonStr() << std::endl;

    std::string  params = "hello everyone";
    std::vector<uint8_t> vec(params.begin(), params.end());
    Param pm1("name", "body", vec);
    std::string jsonstr = pm1.ToJsonStr();
    std::cout << "json = " << jsonstr << std::endl;

    std::shared_ptr pm2 = std::make_shared<Param>();
    int ret = pm2->ParseJson(jsonstr);
    if (ret == 0) {
        std::cout << "name = " << pm2->GetName() << " body = " << pm2->GetBody() << " params = " << pm2->GetParams() << std::endl;
    } else {
        std::cout << "some is error" << std::endl;
    }


    return 0;


}
