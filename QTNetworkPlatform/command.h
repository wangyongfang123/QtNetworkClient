#ifndef __COMMAND_H__
#define  __COMMAND_H__
#include "qtnetworkplatform_global.h"
#include<cstdint>
#include<string>

using namespace std;
enum commendtype
{
	CMD_REGISTR,
	CT_MESSAGE,
	CMD_END
};
struct IS
{
	virtual const string to_data()const = 0;
	virtual void  from_data(const string&) = 0;
};
struct Commend :public IS
{
	commendtype type;
	virtual uint16_t len() = 0;

};
struct QTNETWORKPLATFORM_EXPORT CommandRegister :public Commend
{

	string name;
	string password;
	string information;
	string img;

	// Inherited via IS
	virtual const string to_data() const override;
	virtual void from_data(const string &) override;


	// Inherited via Commend
	virtual uint16_t len() override;

};
struct Message :public Commend
{
	virtual const string to_data() const override;
	virtual void from_data(const string &) override;
	virtual uint16_t len() override;

};
struct QTNETWORKPLATFORM_EXPORT Package :public Commend
{
	CommandRegister *registr;
	Commend *message;

	// Inherited via IS
	virtual const string to_data() const override;
	virtual void from_data(const string &) override;

	// Inherited via Commend
	virtual uint16_t len() override;

};
#endif