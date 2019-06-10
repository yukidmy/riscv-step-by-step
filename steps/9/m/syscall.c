#include <stdio.h>
#include <string.h>
#include "../u/syscall.h"
#include "syscall.h"
#include "regs.h"
#include "femto.h"
#include "arch/riscv/encoding.h"
#include "arch/riscv/machine.h"
#include "arch/riscv/csr.h"
#include "consts.h"

static void handle_write(uintptr_t* regs, uintptr_t mepc, const task_t* curr)
{
    uintptr_t pa = va_to_pa(curr->pte, mepc, 0);
    char *c = (char*)(regs[REG_CTX_A2] + pa);
    putchar(*c);
}

void handle_syscall(uintptr_t* regs, uintptr_t mepc, const task_t* curr)
{
   switch (regs[REG_CTX_A0]) {
   case SYSCALL_WRITE:
       handle_write(regs, mepc, curr);
       break;
   case SYSCALL_EXIT:
       // FIXME: tentative implementation
       exit(regs[REG_CTX_A1]);
   default:
       break;
   }
   write_csr(mepc, mepc + 4);
   return;
}

