use NCR;
create table item_master (item_no int,item_name varchar(10),QoH int)

insert into item_master values(1,'pen',10)

insert into item_master values(2,'pencil',20)

insert into item_master values(3,'notebook',15)

insert into item_master values(4,'scale',0)

select * from item_master
DECLARE

@item varchar(10), @qty_on_hand int;
   
begin
set @item = 'notebook'   
set  @qty_on_hand = (select QoH from item_master where item_name=@item)

   if @qty_on_hand > 0
           begin
		   update item_master set QoH=QoH-1 where item_name='notebook'
           	   print 'Quantity on hand updated.'
	   end
   else 
        print 'Sufficient Quantity not available'
     
end