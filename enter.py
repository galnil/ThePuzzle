" handle the entering to the maze"""
import sys
import re
import subprocess

class WrongPassword(Exception):
	"""wrong password"""
	pass	

class WrongUserName(Exception):
	"""wrong user name"""
	pass

def usage():
	print('usage: python [file] [user_name] [password]')
	sys.exit(1)

def first_enter():
	"""
	check if the user run the program with the correct parameters, if not, the program exits and usage message is printed
	"""
	try:
		input_file, entered_user_name, entered_password = tuple(sys.argv[1:])
		return input_file, entered_user_name, entered_password
	except ValueError:
		usage()

class BlackBox(object):
	"""
	this class representesd the black box system and contains all the operations which the system can execute
	"""
	def __init__(self, input_file, entered_user_name, entered_password):
		self.input_file = input_file
		self.entered_password = entered_password 
		self.entered_user_name = entered_user_name
		self.file_user_name = None
		self.file_password = None
		self.insaide = False

	def get_user_name_and_password(self):
		"""
		read the user_name and the password from the input file
		the user name is the value of the first word after the word 'user_name:'
		the password is the first word after the word 'password:'
		"""
		try:
			with open(self.input_file, 'r') as f:
				list_line = re.split('[\n ]', f.read())
				try:
					file_user_name = list_line[list_line.index('user_name:') + 1]
				except ValueError:
					print('file {} does not contain "user_name:"'.format(self.input_file))
					sys.exit(1)
				try:
					file_password = list_line[list_line.index('password:') + 1]
				except ValueError:
					print('file {} does not contain "password:"'.format(self.input_file))
					sys.exit(1)
				self.file_user_name = file_user_name
				self.file_password = file_password
		except OSError:
			print('file {} dont exist'.format(self.input_file))
			sys.exit(1)
		
	def get_into_the_system(self):
		"""
		check if the user name and the password the user havs entered is equal to the user name and the password which wrote in the input file 
		"""
		try:
			if self.entered_user_name != self.file_user_name:
				raise(WrongUserName)
			if self.entered_password != self.file_password:
				raise(WrongPassword)
		except WrongUserName:
				print('wrong user name')
				sys.exit(1)
		except WrongPassword:
			print('wrong password')
			sys.exit(1)	
		self.insaide = True
		print('you have the first stage\ncongradulation!!!!!!!!')
		subprocess.Popen(['xdg-open', './congradulations.jpg']).wait()
		sys.exit(0)
if __name__ == '__main__':
	input_file, entered_user_name, entered_password = first_enter()
	box = BlackBox(input_file, entered_user_name, entered_password)
	box.get_user_name_and_password()
	box.get_into_the_system()
