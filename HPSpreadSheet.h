#ifndef _HPSPREADSHEET_H_
#define _HPSPREADSHEET_H_

#include <string>
using std::wstring;

class CHPSpreadSheet
{
public:
	/////////////////////////////////////////////////////////////
	// C O N S T R U C T E R S
	/////////////////////////////////////////////////////////////
	CHPSpreadSheet(void);
	CHPSpreadSheet(double initValue);
	explicit CHPSpreadSheet(const wstring& initValue, bool isValue);
	CHPSpreadSheet(const CHPSpreadSheet& source, bool isValue);

	/////////////////////////////////////////////////////////////
	// D E S T R U C T E R
	/////////////////////////////////////////////////////////////
	~CHPSpreadSheet(void);

	/////////////////////////////////////////////////////////////
	// O P E R A T O R S
	/////////////////////////////////////////////////////////////
	CHPSpreadSheet& operator=(const CHPSpreadSheet& rhs);
	const CHPSpreadSheet operator-() const;

	friend const CHPSpreadSheet operator+(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource);
	friend const CHPSpreadSheet operator-(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource);
	friend const CHPSpreadSheet operator*(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource);
	friend const CHPSpreadSheet operator/(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource);

	friend bool operator==(const CHPSpreadSheet& lhs, const CHPSpreadSheet& rhs);
	friend bool operator<(const CHPSpreadSheet& lhs, const CHPSpreadSheet& rhs);
	friend bool operator>(const CHPSpreadSheet& lhs, const CHPSpreadSheet& rhs);
	friend bool operator!=(const CHPSpreadSheet& lhs, const CHPSpreadSheet& rhs);
	friend bool operator<=(const CHPSpreadSheet& lhs, const CHPSpreadSheet& rhs);
	friend bool operator>=(const CHPSpreadSheet& lhs, const CHPSpreadSheet& rhs);

	CHPSpreadSheet& operator+=(const CHPSpreadSheet& rhs);
	CHPSpreadSheet& operator-=(const CHPSpreadSheet& rhs);
	CHPSpreadSheet& operator*=(const CHPSpreadSheet& rhs);
	CHPSpreadSheet& operator/=(const CHPSpreadSheet& rhs);

	CHPSpreadSheet& operator++(); // prefix
	const CHPSpreadSheet operator++(int); // postfix
	CHPSpreadSheet& operator--(); // prefix 
	const CHPSpreadSheet operator--(int); // postfix

	//friend ostream& operator<<(ostream& wostr, const CHPSpreadSheet& cell);
	//friend istream& operator>>(istream& wistr, CHPSpreadSheet& cell);

	operator wstring() const;
	operator double() const;

	/////////////////////////////////////////////////////////////
	// O P E R A T I O N S
	/////////////////////////////////////////////////////////////
	void SetValue(double inValue);
	void SetString(const wstring& inString, bool isValue);

	double GetDbValue() const
	{
		m_lNumAccesses++;
		return m_dValue;
	}
  
	wstring GetStrValue() const
	{
		m_lNumAccesses++;
		return m_wsValstr;
	}

	wstring GetData() const
	{
		m_lNumAccesses++;
		return m_wsDataStr;
	}

	void CoreDataShift(const CHPSpreadSheet& source, bool isValue);

	static wstring DoubleToString(double inValue);
	static double StringToDouble(const wstring& inString);

public:

protected:
	double m_dValue;
	wstring m_wsValstr;
	wstring m_wsDataStr;
	bool	m_bIsValue;

	mutable long m_lNumAccesses;
};


#endif