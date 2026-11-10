using ContosoPizza.Data;
using ContosoPizza.Models;

using ContosoPizzaContext context = new();

// Product veggieSpecial = new() { Name = "Veggie Special Pizza", Price = 9.99M };
// context.Products.Add(veggieSpecial);
//
// // Product deluxeMeat = new() { Name = "Deluxe Meat Pizza", Price = 12.99M };
// context.Add(new Product() { Name = "Deluxe Meat Pizza", Price = 12.99M });
// context.SaveChanges();
// var products = context.Products.Where(p => p.Price > 10.00M).OrderBy(p => p.Name);
//
//
var veggieSpecial = context.Products.Where(p => p.Name == "Veggie Special Pizza").FirstOrDefault();

// if (veggieSpecial is Product)
// {
//     veggieSpecial.Price = 10.99M;
// }
//
// if (veggieSpecial is not null)
// {
//     veggieSpecial.Price = 10.99M;
// }

// veggieSpecial?.Price = 10.99M;
if (veggieSpecial is not null)
    context.Remove(veggieSpecial);

context.SaveChanges();

var products =
    from product in context.Products
    where product.Price > 10.00M
    orderby product.Name
    select product;
foreach (Product p in products)
{
    Console.WriteLine($"Id:         {p.Id}");
    Console.WriteLine($"Name:       {p.Name}");
    Console.WriteLine($"Price:      {p.Price}");
    Console.WriteLine(new string('_', 20));
}
