#pragma once

namespace RenHook
{
    class Capstone
    {
    public:

        Capstone();
        Capstone(const Capstone&) = delete;
        Capstone(Capstone&&) = delete;

        ~Capstone();

        Capstone& operator=(const Capstone&) = delete;

        Capstone& operator=(Capstone&&) = delete;

        const size_t Disassemble(const uintptr_t aAddress, const size_t aSize);

        cs_insn* GetInstructionAt(size_t aIndex) const;

        const size_t GetInstructionSize(size_t aIndex) const;

        const size_t GetTotalNumberOfInstructions() const;

    private:

        void ReleaseInstructions();

        csh m_handle;

        cs_insn* m_instructionInfo;

        size_t m_instructions;
    };
}