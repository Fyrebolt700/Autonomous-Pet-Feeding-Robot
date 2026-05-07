
int pressTime()
{
	while(!TouchLED.pressing)
	{
		Brain.Timer.reset();
	}
	while(TouchLED.pressing)
	{
		int time = Brain.Timer.value();
	}
	return time;
}

int main()
{
	int max_time = -10000;
	for (int i = 0; i < 5; i ++)
	{
		int time = pressTime();
		if(time > max_time)
		{
			max_time = time;
		}
	}
	Brain.Screen.print("&d",max_time);
}








void turncw(int degrees)
{
	left.Motor.setVelocity(20,percent);
	leftMotor.spinToPosition(degrees, degrees, wait);
}

int main(){
	int degrees = 0;
	configureAllSensors();
	while(!TouchLED.pressing()){}
	for(int i = 0; i < 10; i++)
	{
		prev_color = Optical.color();
		leftMotor.spin(forward);
		rightMotor.spin(forward);
		while(prev_color == Optical.color()){}
		leftMotor.stop();
		rightMotor.stop();
		if((i+1)%2 == 0)
		{
			degrees = -144;
		}
		else
		{
			degrees = -44;
		}
		turncw(degrees);
	}
}















