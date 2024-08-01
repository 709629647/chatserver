#pragma once
#include <google/protobuf/service.h>
class MprpcController: public google::protobuf::RpcController
{
private:
    bool is_failed_;
    std::string err_text;
public:
    MprpcController(/* args */);
    ~MprpcController();
    void Reset();
    bool Failed() const;
    std::string ErrorText() const;
    void SetFailed(const std::string& reason);

    void StartCancel();
    bool IsCanceled() const;
    void NotifyOnCancel(google::protobuf::Closure* callback);
};

