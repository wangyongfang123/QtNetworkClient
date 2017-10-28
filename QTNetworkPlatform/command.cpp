#include "command.h"
#include<cassert>
typedef uint32_t LenType;
typedef uint32_t EnumType;
static string get_value(const string&data, const string&field_name, const string&end_name)
{
	size_t start = data.find(field_name) + field_name.length();
	size_t end = data.find(end_name);
	string ret = data.substr(start, end - start);
	return ret;
}
static string get_value(const string&data, const string&name)
{
	string field_start = '<' + name + '>';
	string field_end = "</" + name + '>';
	return get_value(data, field_start, field_end);
}
commendtype CommandRegister::type()const
{
	return CT_REGISTER;
}
const string CommandRegister::to_data() const
{
	string data = "";
	data += "<type>";
	uint32_t tmp = type();
	data.append((const char*)&tmp, sizeof(EnumType));
	data += "</type>";

	data += "<name>";
	data += this->name;
	data += "</name>";

	data += "<password>";
	data += this->password;
	data += "</password>";

	data += "<information>";
	data += this->information;
	data += "</information>";


	data += "<img>";
	data += this->img;
	data += "</img>";
	return data;
}

void CommandRegister::from_data(const string &data)
{
	//type = (commendtype)*(uint32_t*)(get_value(data, "type").data());
	name = get_value(data, "name");
	password = get_value(data, "password");
	information = get_value(data, "information");
	img = get_value(data, "img");
}
int CommandRegister::length()const
{
	assert(0);
	return uint16_t();
}
static const char*package_start = "<start>";
static const char*package_end = "<end>";

const string Package::to_data(const Commend& cmd)
{
	string data;
	data += package_start;
	string tData;
	tData = cmd.to_data();
	uint16_t len = tData.length();
	data.append((const char*)&len, sizeof(uint16_t));
	data.append(tData);
	data.append(package_end);
	return data;
}

Package::Package():command(0)
{
}

Package::Package(Commend * cmd):command(cmd)
{
}
Package::~Package()
{
	if (command != 0)
	{
		delete command;
	}
}
const string Package::to_data() const
{
	
	return Package::to_data(*this->command);
}
int Package::data_len() const
{
	assert(command != 0);
	if (command == 0)
	{
		return -1;
	}
	return strlen(package_start)+sizeof(LenType)+command->length()+strlen(package_end);

}
const Commend* Package::getCmd()const
{
	return command;
}
void Package::from_data(const string &data)
{
	size_t start = data.find(package_start);
	size_t end_index = data.find(package_end);
	if (start == string::npos|| end_index==string::npos)
	{
		return;
	}
	start += strlen(package_start);
	string slen = data.substr(start, 2);//取命令数据长度
	uint16_t len = *(uint16_t*)slen.data();
	string cmd_data = data.substr(start + sizeof(uint16_t), len);
	//取命令类型
	string stype = get_value(cmd_data, "type");
	uint32_t type = *(uint32_t*)stype.data();
	switch (type)
	{
	case CMD_REGISTR:
	{
		registr = new CommandRegister;
		registr->from_data(cmd_data);
	}
	break;
	//case CT_MESSAGE:
	//{
	//	message = new CommandMessage;
	//}
	break;
	default:
		break;

	}
	//if (message != 0)
	//{
	//	message->from_data(cmd_data);
	//}
}

const string Message::to_data() const
{


	return 0;
}

void Message::from_data(const string &)
{



}

int Message::length() const
{
	assert(0);
	return uint16_t();
}
