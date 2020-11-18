unsigned char sc[] = {
	0x50, // push rax (save rax)
	0x48, 0xB8, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, // mov rax, 0CCCCCCCCCCCCCCCCh (place holder for return address)  可从rip中获取：sc[3]
	0x9c,                                                                   // pushfq
	0x51,                                                                   // push rcx
	0x52,                                                                   // push rdx
	0x53,                                                                   // push rbx
	0x55,                                                                   // push rbp
	0x56,                                                                   // push rsi
	0x57,                                                                   // push rdi
	0x41, 0x50,                                                             // push r8
	0x41, 0x51,                                                             // push r9
	0x41, 0x52,                                                             // push r10
	0x41, 0x53,                                                             // push r11
	0x41, 0x54,                                                             // push r12
	0x41, 0x55,                                                             // push r13
	0x41, 0x56,                                                             // push r14
	0x41, 0x57,                                                             // push r15
	0x68, 0xef,0xbe,0xad,0xde,

	/* 实现调用 */
	0x48, 0xB9, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, // mov rcx, 0CCCCCCCCCCCCCCCCh (place holder for DLL path name)    sc[41]
	0x48, 0xB8, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, // mov rax, 0CCCCCCCCCCCCCCCCh (place holder for LoadLibrary)	   sc[51]
	0xFF, 0xD0,                // call rax (call LoadLibrary)

	0x58, // pop dummy
	0x41, 0x5F,                                                             // pop r15
	0x41, 0x5E,                                                             // pop r14
	0x41, 0x5D,                                                             // pop r13
	0x41, 0x5C,                                                             // pop r12
	0x41, 0x5B,                                                             // pop r11
	0x41, 0x5A,                                                             // pop r10
	0x41, 0x59,                                                             // pop r9
	0x41, 0x58,                                                             // pop r8
	0x5F,                                                                   // pop rdi
	0x5E,                                                                   // pop rsi
	0x5D,                                                                   // pop rbp
	0x5B,                                                                   // pop rbx
	0x5A,                                                                   // pop rdx
	0x59,                                                                   // pop rcx
	0x9D,                                                                   // popfq
	0x58,                                                                   // pop rax
	0xC3                                                                    // ret
};