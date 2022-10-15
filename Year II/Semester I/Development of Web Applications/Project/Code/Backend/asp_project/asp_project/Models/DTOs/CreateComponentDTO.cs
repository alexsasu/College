using asp_project.Models.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.DTOs
{
    public class CreateComponentDTO
    {
        public string ComponentName { get; set; }
        public string Seller { get; set; }
        public bool RecommendedForGaming { get; set; }
        public double Price { get; set; }
        public int ClientId { get; set; }
    }
}
