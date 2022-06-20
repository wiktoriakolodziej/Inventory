#pragma once
#include <string>
#include <ctime> // mktime() - czas tm do time_t
#include <exception>



namespace Inventory {
	class InvalidData : public std::exception {

	};
	class Date {
		std::string day, month, year;
	public:
		Date(const std::string date)
		{
			int i = 0;
			time_t current_time = time(0);
			struct tm now;
			localtime_s(&now, &current_time);
			if (date.size() > 10 || date.size() < 8)throw InvalidData();
			while (i < date.size() && date[i] != '.' && date[i] != ' ' && date[i] != ',') {
				day.push_back(date[i]);
				i++;
			}
			if (std::stoi(day) > 31 || std::stoi(day) < 1 || day.size() > 2 || day.size() < 1)throw InvalidData();
			
			i++;
			while (i < date.size() && date[i] != '.' && date[i] != ' ' && date[i] != ',') {
				month.push_back(date[i]);
				i++;
			}
			if (std::stoi(month) > 12 || std::stoi(month) < 1 || month.size() > 2 ||  month.size() < 1)throw InvalidData();
			i++;
			while (i < date.size() && date[i] != '.' && date[i] != ' ' && date[i] != ',') {
				year.push_back(date[i]);
				i++;
			}
			if (std::stoi(year) > 2040 || std::stoi(year) < (now.tm_year + 1900) || year.size() > 4 || year.size() < 1)throw InvalidData();
			if(std::stoi(year) == (now.tm_year + 1900) && ((now.tm_mon + 1) > std::stoi(month) || ((now.tm_mon + 1) == std::stoi(month) && now.tm_mday > std::stoi(day))))
				throw InvalidData();
		}
		std::time_t ToTime_t() {
			std::time_t now = time(0);
			struct tm  service;
			localtime_s(&service, &now);
	
			service.tm_mon = stoi(month) - 1;
			service.tm_year = stoi(year) - 1900;
			service.tm_mday = stoi(day);
			return mktime(&service);
		}
		bool operator == (const Date& c) {
			return day == c.day && month == c.month && year == c.year;
		}
		Date& operator = (const Date& c) {
			if (*this == c)
				return *this;
			day = c.day;
			month = c.month;
			year = c.year;
			return *this;
		}
		friend std::ostream& operator <<(std::ostream& c, const Date& d);

	};
}
