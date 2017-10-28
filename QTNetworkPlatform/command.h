#ifndef __COMMAND_H__
#define  __COMMAND_H__
#include "qtnetworkplatform_global.h"
#include<cstdint>
#include<string>

//using namespace std;
using std::string;
enum commendtype
{
	CMD_REGISTR,
	CT_MESSAGE,
	CT_REGISTER,
	CMD_END
};
struct IS
{
	virtual const string to_data()const = 0;
	virtual void  from_data(const string&) = 0;
};
struct Commend :public IS
{
	virtual commendtype type() const=0;
	virtual int length () const= 0;
	virtual ~Commend(){}

};
struct QTNETWORKPLATFORM_EXPORT CommandRegister :public Commend
{

	string name;
	string password;
	string information;
	string img;
	commendtype type() const;
	//CommandRegister();
	// Inherited via IS
	virtual const string to_data() const override;
	virtual void from_data(const string &) override;


	// Inherited via Commend
	virtual int length() const override;

};
struct Message :public Commend
{
	virtual const string to_data() const override;
	virtual void from_data(const string &) override;
	virtual int length() const override;

};
struct QTNETWORKPLATFORM_EXPORT Package :public IS
{
	CommandRegister *registr;
	//Commend *command;
	Package();
	~Package();
	Package(Commend * cmd);
	int data_len()const;
	const Commend* getCmd() const;
	// Inherited via IS
	virtual const string to_data() const override;
	virtual void from_data(const string &) override;
	static const string to_data(const Commend&);
	// Inherited via Commend
	//virtual uint16_t len() override;
private:
	Commend *command;
};
#endif