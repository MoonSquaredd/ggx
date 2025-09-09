int RandomSeed = 0;

void RandomInit(int num) 
{
  RandomSeed = num;
  return;
};

int Random(void)
{
  RandomSeed = RandomSeed * 0x1579 + 0x7fa9;
  return RandomSeed & 0xffff;
};
