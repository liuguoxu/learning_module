#write file

Dir = './'
def write_file(name, string):
	whole_name = Dir + name
	file_tmp = open(whole_name, 'w')
	file_tmp.write(string)
	file_tmp.close()
	print('done')

write_file('tmp.tmp', 'heheda')
