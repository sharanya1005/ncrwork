declare
 	@input_string varchar(10), 
	@output_string varchar(10),
 	@length int
 	
 begin
  	set @input_string = 'Database'
  	set  @length = len(@input_string)
 
 	while(@length>0)
 	begin
 		set @output_string =concat(@output_string,substring(@input_string, @length, 1))
 		set @length  = @length-1
 	end
	print @output_string 
 end

