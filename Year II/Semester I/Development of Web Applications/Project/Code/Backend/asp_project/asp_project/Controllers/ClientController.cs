using asp_project.Models.Entities;
using asp_project.Models.DTOs;
using asp_project.Repositories.ClientRepository;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.JsonPatch;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Cors;

namespace asp_project.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ClientController : ControllerBase
    {
        private readonly IClientRepository _repository;
        public ClientController(IClientRepository repository)
        {
            _repository = repository;
        }


        [HttpPost]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> CreateClient([FromBody] CreateClientDTO dto)
        {
            Client newCli = new Client();

            newCli.ClientLastName = dto.ClientLastName;
            newCli.ClientFirstName = dto.ClientFirstName;
            newCli.DeliveryAddress = dto.DeliveryAddress;

            _repository.Create(newCli);

            await _repository.SaveAsync();

            return Ok(new ClientDTO(newCli));
        }


        [HttpGet("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetClientByIdWithDeliveryAddress(int id)
        {
            var client = await _repository.GetClientByIdWithDeliveryAddress(id);
            if (client == null)
            {
                return NotFound("The specified client does not exist!");
            }

            return Ok(new ClientDTO(client));
        }


        [HttpGet("getAllClientsWithTheirDeliveryAddress")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetAllClientsWithTheirDeliveryAddress()
        {
            var clients = await _repository.GetAllClientsWithTheirDeliveryAddress();

            var clientsToReturn = new List<ClientDTO>();
            foreach (var cli in clients)
            {
                clientsToReturn.Add(new ClientDTO(cli));
            }

            return Ok(clientsToReturn);
        }


        [HttpGet("getNumberOfComponentsBoughtByEachClient")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetNumberOfComponentsBoughtByEachClient()
        {
            var components = await _repository.GetComponentsBought();

            var grouped = components.GroupBy(x => x.ClientId);
            grouped.ToList().ForEach(x =>
                Console.WriteLine($"Client with id {x.Key} has bought {x.Count()} component(s)."));

            return Ok();
        }


        [HttpPatch("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> PatchClient([FromRoute] int id, [FromBody] JsonPatchDocument<Client> cli)
        {
            var cliToUpdate = await _repository.GetByIdAsync(id);
            if (cliToUpdate == null)
            {
                return NotFound("The specified client does not exist!");
            }

            cli.ApplyTo(cliToUpdate, ModelState);
            if (!ModelState.IsValid)
            {
                return BadRequest();
            }

            _repository.Update(cliToUpdate);

            await _repository.SaveAsync();

            return Ok(cliToUpdate);
        }


        [HttpDelete("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> DeleteClient(int id)
        {
            var cli = await _repository.GetByIdAsync(id);
            if (cli == null)
            {
                return NotFound("The specified client does not exist!");
            }

            _repository.Delete(cli);

            await _repository.SaveAsync();

            var newClients = await _repository.GetAllClientsWithTheirDeliveryAddress();

            var newClientsToReturn = new List<ClientDTO>();
            foreach (var c in newClients)
            {
                newClientsToReturn.Add(new ClientDTO(c));
            }

            return Ok(newClientsToReturn);
        }
    }
}
