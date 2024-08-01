#include "MprpcController.h"

MprpcController::MprpcController(/* args */)
{
    is_failed_ = false;
    err_text = "";
}

MprpcController::~MprpcController()
{
}

void MprpcController::Reset()
{
    is_failed_ = false;
    err_text = "";
}
bool MprpcController::Failed() const
{
    return is_failed_;
}
std::string MprpcController::ErrorText() const
{
    return err_text;
}
void MprpcController::SetFailed(const std::string& reason)
{
    is_failed_ = true;
    err_text = reason;
}

bool MprpcController::IsCanceled() const
{
    return false;
}
void MprpcController::StartCancel()
{

}
void MprpcController::NotifyOnCancel(google::protobuf::Closure* callback)
{}