// e4 use table get code ez: (self-explian)

void decDcrypt()  {
	int stor = -1;
	if(GetSize("AUX_INFO") > 16)
	{
		unsigned mem[20];
		Read("AUX_INFO", mem, 20);
		stor *(mem + 13);
	}
	if(stor < 0)
		return;
	unsigned char* p = decemb + (stor * 257), c[2], dec[256], temp, *ptr;
	c[0] = 0xe8;
	c[1] = *p;
	memcpy(dec, ++p, 256);
	unsigned int sz = ReadSec(mSec);
	if(sz) {
		ptr = mSec;
		do
		{
			c[0]++;
			c[1] += dec[c[0]];
			swap(dec[c[0]], dec[c[1]]);
			temp += dec[c[0]];
			temp = dec[temp];
			*ptr ^= temp;
			ptr++;
		} while(--sz);
	}
}