#ifndef COMMAND_H
#define COMMAND_H


class Command
{
    public:
        bool execute();
        Command();
        virtual ~Command();
    protected:
    private:
};

#endif // COMMAND_H
