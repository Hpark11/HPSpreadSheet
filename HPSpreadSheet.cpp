#include "HPSpreadSheet.h"

#include <iostream>
#include <sstream>

using namespace std;

CHPSpreadSheet::CHPSpreadSheet()
{
	m_dValue		= 0;
	m_lNumAccesses	= 0;
}

CHPSpreadSheet::~CHPSpreadSheet()
{

}

CHPSpreadSheet::CHPSpreadSheet(double initValue)
{
	SetValue(initValue);
	m_lNumAccesses = 0;
}

CHPSpreadSheet::CHPSpreadSheet(const CHPSpreadSheet& source, bool isValue)
{
	CoreDataShift(source, isValue);
	m_lNumAccesses = 0;
}

CHPSpreadSheet::CHPSpreadSheet(const wstring& initValue, bool isValue)
{
	SetString(initValue, isValue);
	m_bIsValue = isValue;
	m_lNumAccesses = 0;
}

void CHPSpreadSheet::SetValue(double inValue)
{
	m_bIsValue	= true;
	m_dValue	= inValue;
	m_wsValstr	= DoubleToString(inValue);
	return;
}

void CHPSpreadSheet::SetString(const wstring& inString, bool isValue)
{
	if(isValue == true)
	{
		m_wsValstr = inString;
		m_dValue = StringToDouble(inString);
	}
	else
	{
		m_wsDataStr = inString;
	}
	return;
}

void CHPSpreadSheet::CoreDataShift(const CHPSpreadSheet& source, bool isValue)
{
	if(isValue == true)
	{
		m_dValue	= source.m_dValue;
		m_wsValstr	= source.m_wsValstr;
	}
	else
	{
		m_wsDataStr = source.m_wsDataStr;
	}
	
	m_bIsValue	= source.m_bIsValue;
	return;
}

wstring CHPSpreadSheet::DoubleToString(double inValue)
{
	wostringstream wostr;

	wostr << inValue;
	
	return (wostr.str());
}

double CHPSpreadSheet::StringToDouble(const wstring& inString)
{
	double temp;
	
	wistringstream wistr(inString);

	wistr >> temp;
	if(wistr.fail() || !wistr.eof())
	{
		return (0);
	}

	return (temp);
}

const CHPSpreadSheet operator+(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	CHPSpreadSheet hpElement;
	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		hpElement.SetValue(lSource.m_dValue + rSource.m_dValue);
	}
	else
	{
		
	}

	return (hpElement);
}

const CHPSpreadSheet operator-(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	CHPSpreadSheet hpElement;
	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		hpElement.SetValue(lSource.m_dValue - rSource.m_dValue);
	}
	else
	{

	}

	return (hpElement);
}

const CHPSpreadSheet operator*(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	CHPSpreadSheet hpElement;
	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		hpElement.SetValue(lSource.m_dValue * rSource.m_dValue);
	}
	else
	{

	}

	return (hpElement);
}

const CHPSpreadSheet operator/(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	CHPSpreadSheet hpElement;
	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		hpElement.SetValue(lSource.m_dValue / rSource.m_dValue);
	}
	else
	{

	}

	return (hpElement);
}

CHPSpreadSheet& CHPSpreadSheet::operator+=(const CHPSpreadSheet& rSource)
{
	if(m_bIsValue == true && rSource.m_bIsValue == true)
	{
		SetValue(m_dValue + rSource.m_dValue); // call set to update mValue and mString
	}
	else
	{

	}

	return (*this);
}

CHPSpreadSheet& CHPSpreadSheet::operator-=(const CHPSpreadSheet& rSource)
{
	if(m_bIsValue == true && rSource.m_bIsValue == true)
	{
		SetValue(m_dValue - rSource.m_dValue); // call set to update mValue and mString
	}
	else
	{

	}

	return (*this);
}

CHPSpreadSheet& CHPSpreadSheet::operator*=(const CHPSpreadSheet& rSource)
{
	if(m_bIsValue == true && rSource.m_bIsValue == true)
	{
		SetValue(m_dValue * rSource.m_dValue); // call set to update mValue and mString
	}
	else
	{

	}

	return (*this);
}

CHPSpreadSheet& CHPSpreadSheet::operator/=(const CHPSpreadSheet& rSource)
{
	if(m_bIsValue == true && rSource.m_bIsValue == true)
	{
		SetValue(m_dValue / rSource.m_dValue); // call set to update mValue and mString
	}
	else
	{
	
	}

	return (*this);
}

bool operator==(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	bool bComparison = false;

	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		if(lSource.m_dValue == rSource.m_dValue)
		{
			bComparison = true;
		}
		else
		{
		}
	}
	else
	{
	}

	return bComparison;
}

bool operator<(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	bool bComparison = false;

	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		if(lSource.m_dValue < rSource.m_dValue)
		{
			bComparison = true;
		}
		else
		{
		}
	}
	else
	{
	}

	return bComparison;
}

bool operator>(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	bool bComparison = false;

	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		if(lSource.m_dValue > rSource.m_dValue)
		{
			bComparison = true;
		}
		else
		{
		}
	}
	else
	{
	}

	return bComparison;
}

bool operator!=(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	bool bComparison = false;

	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		if(lSource.m_dValue != rSource.m_dValue)
		{
			bComparison = true;
		}
		else
		{
		}
	}
	else
	{
	}

	return bComparison;
}

bool operator<=(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	bool bComparison = false;

	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		if(lSource.m_dValue <= rSource.m_dValue)
		{
			bComparison = true;
		}
		else
		{
		}
	}
	else
	{
	}

	return bComparison;
}

bool operator>=(const CHPSpreadSheet& lSource, const CHPSpreadSheet& rSource)
{
	bool bComparison = false;

	if(lSource.m_bIsValue == true && rSource.m_bIsValue == true)
	{
		if(lSource.m_dValue >= rSource.m_dValue)
		{
			bComparison = true;
		}
		else
		{
		}
	}
	else
	{
	}

	return bComparison;
}


CHPSpreadSheet& CHPSpreadSheet::operator++()
{
	if(m_bIsValue == true)
	{
		SetValue(m_dValue + 1);
	}
	else
	{

	}
	
	return *this;
}

const CHPSpreadSheet CHPSpreadSheet::operator++(int)
{
	CHPSpreadSheet oldCell(*this);
	if(m_bIsValue == true)
	{
		SetValue(m_dValue + 1);
	}
	else
	{

	}

	return oldCell; // return the old value
}

CHPSpreadSheet& CHPSpreadSheet::operator--()
{
  if(m_bIsValue == true)
	{
		SetValue(m_dValue - 1);
	}
	else
	{

	}
	
	return *this;
}

const CHPSpreadSheet CHPSpreadSheet::operator--(int)
{
	CHPSpreadSheet oldCell(*this);
	if(m_bIsValue == true)
	{
		SetValue(m_dValue - 1);
	}
	else
	{

	}

	return oldCell; // return the old value
}

CHPSpreadSheet& CHPSpreadSheet::operator=(const CHPSpreadSheet& rSource)
{
	if (this == &rSource) {
		return *this;
	}

	if(rSource.m_bIsValue == true)
	{
		m_dValue	= rSource.m_dValue;
		m_wsValstr	= rSource.m_wsValstr;
	}
	else
	{
		m_wsDataStr = rSource.m_wsDataStr;
	}
	
	m_bIsValue	= rSource.m_bIsValue;
	m_lNumAccesses = rSource.m_lNumAccesses;
	return *this;
}

const CHPSpreadSheet CHPSpreadSheet::operator-() const
{
  CHPSpreadSheet newCell(*this);
  newCell.SetValue(-m_dValue); // call set to update mValue and mStr

  return newCell;
}

//wistream& operator>>(wistream& wistr, CHPSpreadSheet& cell)
//{
//	wstring temp;
//	wistr >> temp;
//
//	if(cell.m_bIsValue == true)
//	{
//		cell.SetString(temp, true);
//	}
//	else
//	{
//		cell.SetString(temp, false);
//	}
//	
//	return wistr;
//}
//
//wostream& operator<<(wostream& wostr, const CHPSpreadSheet& cell)
//{
//	if(cell.m_bIsValue == true)
//	{
//		wostr << cell.m_wsValstr;
//	}
//	else
//	{
//		wostr << cell.m_wsDataStr;
//	}
//	
//	return wostr;
//}

