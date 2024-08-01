#include "MprpcConfig.h"
#include <string>
#include <iostream>
void Trim(std::string& src_buf)
{
	int idx = src_buf.find_first_not_of(' ');
	if (idx != -1)
	{
		src_buf = src_buf.substr(idx, src_buf.size() - idx);
	}
	idx = src_buf.find_last_not_of(' ');
	if (idx != -1)
	{
		src_buf = src_buf.substr(0, idx + 1);
	}
}
void MprpcConfig::LoadConfig(const char *name)
{
	FILE *fp = fopen(name, "r");
	while (!feof(fp))
	{
		char buf[128] = {0};
		fgets(buf, 128, fp);
		std::string src_buf(buf);
		Trim(src_buf);

		if (src_buf[0] == '#' || src_buf.empty())
		{
			continue;
		}
		// std::cout << src_buf << std::endl;
		int idx = src_buf.find('=');
		if (idx == -1)
		{
			std::cerr << "invalid input";
			exit(EXIT_FAILURE);
		}

		std::string key;
		std::string value;
		key = src_buf.substr(0, idx);
		Trim(key);
		int endidx = src_buf.find('\n');
		value = src_buf.substr(idx + 1, endidx - idx -1);
		Trim(value);
		m.insert({key, value});
		// std::cout << key << " " <<value << std::endl;
	}
}

std::string MprpcConfig::GetConfigValue(const std::string &key)
{
	auto it = m.find(key);
	if (it != m.end())
	{
		return it->second;
	}
	return "";
}
