import json

with open('dmgops.json') as dmgops:
    data = json.load(dmgops)
    opcount = 1
    for opcode in data['Unprefixed']:
        length = opcode['Length']
        cycles = opcode['TCyclesBranch']
        mnemonic = opcode['Name'].strip().split(' ')[0].lower()
        if mnemonic == 'unused':
            mnemonic = 'invalid'
        opA = '0'
        opB = '0'

        if len(opcode['Name'].split(' ')) > 1:
            opA = opcode['Name'].strip().split(' ')[1].split(',')[0]
        if len(opcode['Name'].split(',')) > 1:
            opB = opcode['Name'].strip().split(',')[1]

        if mnemonic != 'invalid' and mnemonic != 'prefix':
            if len(opA) < 8:
                string = '{' + str(length) + ',\t' + str(cycles) + ',\t' + 'R' + ',\t' + '&' + mnemonic + ',\t\t' + opA + ',\t\t' + opB + '}'
            else:
                string = '{' + str(length) + ',\t' + str(cycles) + ',\t' + 'R' + ',\t' + '&' + mnemonic + ',\t\t' + opA + ',\t' + opB + '}'
        else:
            if len(opA) < 8:
                string = '{' + str(length) + ',\t' + str(cycles) + ',\t' + 'R' + ',\t' + '&' + mnemonic + ',\t' + opA + ',\t\t' + opB + '}'
            else:
                string = '{' + str(length) + ',\t' + str(cycles) + ',\t' + 'R' + ',\t' + '&' + mnemonic + ',\t' + opA + ',\t' + opB + '}'

        print(string + ',')

        opcount = opcount + 1
