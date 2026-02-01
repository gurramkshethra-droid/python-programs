import calendar
month,date,year=map(int,input().split())
days=calendar.weekday(year,month,date)
weeks=["MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"]
print(weeks[days])