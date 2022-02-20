using asp_project.Models.Entities;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Data
{
    public class Context : IdentityDbContext<User, Role, int, 
                            IdentityUserClaim<int>, UserRole, IdentityUserLogin<int>,
                            IdentityRoleClaim<int>, IdentityUserToken<int>>
    {
        public Context(DbContextOptions options) : base(options) { }

        public DbSet<SessionToken> SessionTokens { get; set; }

        public DbSet<Component> Components { get; set; }
        public DbSet<Client> Clients { get; set; }
        public DbSet<DeliveryAddress> DeliveryAddresses { get; set; }
        public DbSet<Employee> Employees { get; set; }
        public DbSet<ClientEmployee> ClientEmployees { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            modelBuilder.Entity<Client>()
                .HasMany(cli => cli.Components)
                .WithOne(comp => comp.Client);

            modelBuilder.Entity<Client>()
                .HasOne(cli => cli.DeliveryAddress)
                .WithOne(delivAdd => delivAdd.Client);

            modelBuilder.Entity<ClientEmployee>().HasKey(cliEmp => new { cliEmp.ClientId, cliEmp.EmployeeId });

            modelBuilder.Entity<ClientEmployee>()
                .HasOne(cliEmp => cliEmp.Client)
                .WithMany(cli => cli.ClientEmployees)
                .HasForeignKey(cliEmp => cliEmp.ClientId);

            modelBuilder.Entity<ClientEmployee>()
                .HasOne(cliEmp => cliEmp.Employee)
                .WithMany(emp => emp.ClientEmployees)
                .HasForeignKey(cliEmp => cliEmp.EmployeeId);

            modelBuilder.Entity<UserRole>(ur =>
            {
                ur.HasKey(ur => new { ur.UserId, ur.RoleId });
                
                ur.HasOne(ur => ur.Role).WithMany(r => r.UserRoles).HasForeignKey(ur => ur.RoleId);
                ur.HasOne(ur => ur.User).WithMany(u => u.UserRoles).HasForeignKey(ur => ur.UserId);
            });
        }
    }
}
