unsigned char sc[] =
{
	0x68, 0xef, 0xbe, 0xad, 0xde,	// push 0xDEADBEEF
	0x9c,							// pushfd
	0x60,							// pushad
	0x68, 0xef, 0xbe, 0xad, 0xde,	// push 0xDEADBEEF
	0xb8, 0xef, 0xbe, 0xad, 0xde,	// mov eax, 0xDEADBEEF
	0xff, 0xd0,						// call eax
	0x61,							// popad
	0x9d,							// popfd
	0xc3							// ret
};