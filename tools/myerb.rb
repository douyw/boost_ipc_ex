require 'erb'

class MyClass_
  def initialize(arg1, arg2)
    @filename = arg1;  @arg2 = arg2
  end
end
filename = './pro/app_tmpl.rpro'  # @arg1 and @arg2 are used in example.rhtml
erb = ERB.new(File.read(filename))
erb.filename = filename
MyClass = erb.def_class(MyClass_, 'render()')

Dir.glob('./src/*.cpp').each do|f|
  name = File.basename(f, '.cpp')
  next if File.exists?("./pro/#{name}.pro")
#  puts File.basename(f, '.cpp') if File.size?(f)
  content = MyClass.new(name, 123).render()
  File.open("./pro/#{name}.pro", 'w') { |file| file.write(content) }
end

#File.open(yourfile, 'w') { |file| file.write("your text") }
#print MyClass.new('foo', 123).render()
